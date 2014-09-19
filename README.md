This is a simple shim for Direct3D9.  Microsoft has removed D3D9 support from the most recent SDKs, which makes it difficult to write against D3D9 for a quick and dirty project.

Eventually, I'd like to have a few backends:
* D3D9: For instrumentation and/or command injection, similar to [this](http://graphics.stanford.edu/~mdfisher/D3D9Interceptor.html).
* D3D11: For a simpler API over D3D11.
* OpenGL: For porting certain projects to non-Windows targets.

Eventually eventually, having a generalized API shimming architecture like [Detours](http://research.microsoft.com/en-us/projects/detours) would be a fun project.

Toby Jones \([www.turbohex.com](http://www.turbohex.com), [ace.roqs.net](http://ace.roqs.net)\)
