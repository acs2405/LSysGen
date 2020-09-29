

import ctypes
import sys
import os
import threading


class OutputGrabber(object):
    """
    Class used to grab standard output or another stream.
    """
    escape_char = b"\b"

    def __init__(self, stream=None, threaded=False):
        self.origstream = stream
        self.threaded = threaded
        if self.origstream is None:
            self.origstream = sys.stdout
        self.origstreamfd = self.origstream.fileno()
        self.capturedtext = b""
        # Create a pipe so the stream can be captured:
        self.pipe_out, self.pipe_in = os.pipe()

    def __enter__(self):
        self.start()
        return self

    def __exit__(self, type, value, traceback):
        self.stop()

    def start(self):
        """
        Start capturing the stream data.
        """
        self.capturedtext = b""
        # Save a copy of the stream:
        self.streamfd = os.dup(self.origstreamfd)
        # Replace the original stream with our write pipe:
        os.dup2(self.pipe_in, self.origstreamfd)
        if self.threaded:
            # Start thread that will read the stream:
            self.workerThread = threading.Thread(target=self.readOutput)
            self.workerThread.start()
            # Make sure that the thread is running and os.read() has executed:
            time.sleep(0.01)

    def stop(self):
        """
        Stop capturing the stream data and save the text in `capturedtext`.
        """
        # Print the escape character to make the readOutput method stop:
        self.origstream.write(self.escape_char.decode())
        # Flush the stream to make sure all our data goes in before
        # the escape character:
        self.origstream.flush()
        if self.threaded:
            # wait until the thread finishes so we are sure that
            # we have until the last character:
            self.workerThread.join()
        else:
            self.readOutput()
        # Close the pipe:
        os.close(self.pipe_in)
        os.close(self.pipe_out)
        # Restore the original stream:
        os.dup2(self.streamfd, self.origstreamfd)
        # Close the duplicate stream:
        os.close(self.streamfd)

    def readOutput(self):
        """
        Read the stream data (one byte at a time)
        and save the text in `capturedtext`.
        """
        while True:
            char = os.read(self.pipe_out, 1)
            if not char or self.escape_char in char:
                break
            self.capturedtext += char


liblsysgen = ctypes.cdll.LoadLibrary(os.path.dirname(os.path.realpath(__file__)) + '/../../build/liblsysgen.so')

c_lsystem_create = liblsysgen.lsystem_create
c_lsystem_create.argtypes = (ctypes.c_char_p,)
c_lsystem_create.restype = ctypes.c_void_p

c_lsystem_generate = liblsysgen.lsystem_generate
c_lsystem_generate.argtypes = (ctypes.c_void_p,)

c_lsystem_iterate = liblsysgen.lsystem_iterate
c_lsystem_iterate.argtypes = (ctypes.c_void_p, ctypes.c_int)

c_lsystem_get_iteration_number = liblsysgen.lsystem_get_iteration_number
c_lsystem_get_iteration_number.argtypes = (ctypes.c_void_p,)
c_lsystem_get_iteration_number.restype = ctypes.c_int

c_lsystem_get_result_string = liblsysgen.lsystem_get_result_string
c_lsystem_get_result_string.argtypes = (ctypes.c_void_p,)
c_lsystem_get_result_string.restype = ctypes.c_char_p

c_lsystem_to_svg = liblsysgen.lsystem_to_svg
c_lsystem_to_svg.argtypes = (ctypes.c_void_p,)
c_lsystem_to_svg.restype = ctypes.c_char_p

class LSystem:
    def __init__(self, filename, iterations=-1):
        self.filename = filename
        self.iterations = iterations
        # self.errors = ''
        out = OutputGrabber(sys.stderr)
        out.start()
        self.c_lsystem = c_lsystem_create(filename.encode())
        out.stop()
        self.errors = out.capturedtext.decode()
    def valid(self):
        return self.c_lsystem != None
    def generate(self):
        out = OutputGrabber(sys.stderr)
        out.start()
        c_lsystem_generate(self.c_lsystem)
        out.stop()
        self.errors += out.capturedtext.decode()
    def iterate(self, iterations=1):
        out = OutputGrabber(sys.stderr)
        out.start()
        c_lsystem_iterate(self.c_lsystem, iterations)
        out.stop()
        self.errors += out.capturedtext.decode()
    def dumpErrors(self):
        errs = self.errors
        self.errors = ''
        return errs
    def iteration(self):
        return c_lsystem_get_iteration_number(self.c_lsystem)
    def result_to_str(self):
        return c_lsystem_get_result_string(self.c_lsystem).decode()
    def result_to_svg(self):
        return c_lsystem_to_svg(self.c_lsystem).decode()
    def close(self):
        # Clean up the pipe and restore the original stdout
        os.close(stderr_pipe[0])
        os.dup2(stderr_save, stderr_fileno)
        os.close(stderr_save)
