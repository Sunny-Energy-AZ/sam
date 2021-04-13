{
  "targets": [{
    "target_name": "sam",
    "sources": [
      "src/sam.cc",
      "src/pvwattsv5.cc",
      "src/utilityrate5.cc",
      "src/battwatts.cc"
    ],
    "conditions": [
      ['OS=="mac"', {
        "link_settings" : {
          "libraries" : [
            "$(builddir)/../../ssc/lib/mac/ssc.dylib"
          ]
        }
      }],
      ['OS=="linux"', {
        "link_settings" : {
          "libraries" : [
            "-l:ssc.so"
          ]
        }
      }],
      ['OS=="win"', {
        "link_settings": {
          "libraries": [
            "../ssc/lib/win/$(Platform)/ssc.lib"
          ]
        },
        'variables': {
          'build_files': [
            'gyp/dll/libpng12.dll'
          ]
        }
      }]
    ]
  }]
}
