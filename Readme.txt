Для работы тетриса нужно подключить SFML 




C/C++ ->Preprocessor ->Preprocessor Definitions пишем SFML_STATIC

В компоновщике, где прописывали зависимости, для каждого режима отдельно прописываем

Для релиза :
sfml-graphics-s.lib
sfml-window-s.lib
sfml-system-s.lib
sfml-audio-s.lib
opengl32.lib
winmm.lib
gdi32.lib
freetype.lib
openal32.lib
flac.lib
vorbisenc.lib
vorbisfile.lib
vorbis.lib
ogg.lib

Для дебага:
sfml-graphics-s-d.lib
sfml-window-s-d.lib
sfml-system-s-d.lib
sfml-audio-s-d.lib
opengl32.lib
winmm.lib
gdi32.lib
freetype.lib
openal32.lib
flac.lib
vorbisenc.lib
vorbisfile.lib
vorbis.lib
ogg.lib

запускать из дериктории Reliase (там хранится графика)