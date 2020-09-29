from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse
from tempfile import NamedTemporaryFile

import os

from .lsys import LSystem



def index(request):
    context = {
        'code': request.session.get('code', ''),
        'str_result': request.session.get('str_result', ''),
        'svg_result': request.session.get('svg_result', ''),
        'errors': request.session.get('errors', ''),
    }
    return render(request, 'editor/index.html', context)

def run(request):
    try:
        code = request.POST['lsdCode']
        request.session['code'] = code
    except (KeyError):
        pass
    else:
        tf = NamedTemporaryFile(mode='w', suffix='.lsd')
        tf.write(code)
        tf.flush()
        lsys = LSystem(tf.name)
        tf.close()
        if (lsys.valid()):
            lsys.generate()
            request.session['str_result'] = lsys.result_to_str()
            request.session['svg_result'] = lsys.result_to_svg()
        else:
            request.session['str_result'] = ''
            request.session['svg_result'] = ''
        request.session['errors'] = lsys.dumpErrors()

    return HttpResponseRedirect(reverse('editor:index'))
