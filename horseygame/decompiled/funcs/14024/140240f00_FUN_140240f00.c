// Address: 0x140240f00
// Ghidra name: FUN_140240f00
// ============ 0x140240f00 FUN_140240f00 (size=210) ============


char * FUN_140240f00(undefined4 param_1)



{

  switch(param_1) {

  case 0:

    return 

    "uniform mat4 u_projection;\nattribute vec2 a_position;\nattribute vec4 a_color;\nattribute vec2 a_texCoord;\nvarying vec2 v_texCoord;\nvarying vec4 v_color;\n\nvoid main()\n{\n    v_texCoord = a_texCoord;\n    gl_Position = u_projection * vec4(a_position, 0.0, 1.0);\n    gl_PointSize = 1.0;\n    v_color = a_color;\n}\n"

    ;

  case 1:

    return "varying mediump vec4 v_color;\n\nvoid main()\n{\n    gl_FragColor = v_color;\n}\n";

  case 2:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_palette;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 SamplePaletteNearest(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    mediump float index = texture2D(u_texture, uv).r * 255.0;\n    return texture2D(u_palette, vec2((index + 0.5) / 256.0, 0.5));\n}\n\nmediump vec4 SamplePaletteLinear(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    // scale & offset uvs to integer values at texel centers\n    SDL_TEXCOORD_PRECISION vec2 uv_texels = uv * u_texel_size.zw + 0.5;\n\n    // get uvs for the center of the 4 surrounding texels by flooring\n    SDL_TEXCOORD_PRECISION vec4 uv_min_max = vec4((floor(uv_texels) - 0.5) * u_texel_size.xy, (floor(uv_texels) + 0.5) * u_texel_size.xy);\n\n    // blend factor\n    SDL_TEXCOORD_PRECISION vec2 uv_frac = fract(uv_texels);\n\n    // sample all 4 texels\n    mediump vec4 texelA = SamplePaletteNearest(uv_min_max.xy);\n    mediump vec4 texelB = SamplePaletteNearest(uv_min_max.xw);\n    mediump vec4 texelC = SamplePaletteNearest(uv_min_max.zy);\n    mediump vec4 texelD = SamplePaletteNearest(uv_min_max.zw);\n\n    // bilinear interpolation\n    return mix(mix(texelA, texelB, uv_frac.y), mix(texelC, texelD, uv_frac.y), uv_frac.x);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = SamplePaletteNearest(v_texCoord);\n    gl_FragColor = color;\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 3:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_palette;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 SamplePaletteNearest(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    mediump float index = texture2D(u_texture, uv).r * 255.0;\n    return texture2D(u_palette, vec2((index + 0.5) / 256.0, 0.5));\n}\n\nmediump vec4 SamplePaletteLinear(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    // scale & offset uvs to integer values at texel centers\n    SDL_TEXCOORD_PRECISION vec2 uv_texels = uv * u_texel_size.zw + 0.5;\n\n    // get uvs for the center of the 4 surrounding texels by flooring\n    SDL_TEXCOORD_PRECISION vec4 uv_min_max = vec4((floor(uv_texels) - 0.5) * u_texel_size.xy, (floor(uv_texels) + 0.5) * u_texel_size.xy);\n\n    // blend factor\n    SDL_TEXCOORD_PRECISION vec2 uv_frac = fract(uv_texels);\n\n    // sample all 4 texels\n    mediump vec4 texelA = SamplePaletteNearest(uv_min_max.xy);\n    mediump vec4 texelB = SamplePaletteNearest(uv_min_max.xw);\n    mediump vec4 texelC = SamplePaletteNearest(uv_min_max.zy);\n    mediump vec4 texelD = SamplePaletteNearest(uv_min_max.zw);\n\n    // bilinear interpolation\n    return mix(mix(texelA, texelB, uv_frac.y), mix(texelC, texelD, uv_frac.y), uv_frac.x);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = SamplePaletteLinear(v_texCoord);\n    gl_FragColor = color;\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 4:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_palette;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 SamplePaletteNearest(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    mediump float index = texture2D(u_texture, uv).r * 255.0;\n    return texture2D(u_palette, vec2((index + 0.5) / 256.0, 0.5));\n}\n\nmediump vec4 SamplePaletteLinear(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    // scale & offset uvs to integer values at texel centers\n    SDL_TEXCOORD_PRECISION vec2 uv_texels = uv * u_texel_size.zw + 0.5;\n\n    // get uvs for the center of the 4 surrounding texels by flooring\n    SDL_TEXCOORD_PRECISION vec4 uv_min_max = vec4((floor(uv_texels) - 0.5) * u_texel_size.xy, (floor(uv_texels) + 0.5) * u_texel_size.xy);\n\n    // blend factor\n    SDL_TEXCOORD_PRECISION vec2 uv_frac = fract(uv_texels);\n\n    // sample all 4 texels\n    mediump vec4 texelA = SamplePaletteNearest(uv_min_max.xy);\n    mediump vec4 texelB = SamplePaletteNearest(uv_min_max.xw);\n    mediump vec4 texelC = SamplePaletteNearest(uv_min_max.zy);\n    mediump vec4 texelD = SamplePaletteNearest(uv_min_max.zw);\n\n    // bilinear interpolation\n    return mix(mix(texelA, texelB, uv_frac.y), mix(texelC, texelD, uv_frac.y), uv_frac.x);\n}\n\nmediump vec4 GetPixelArtSample(vec2 uv)\n{\n    return texture2D(u_texture, uv);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = SamplePaletteNearest(v_texCoord);\n    gl_FragColor = color;\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 5:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_palette;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 SamplePaletteNearest(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    mediump float index = texture2D(u_texture, uv).r * 255.0;\n    return texture2D(u_palette, vec2((index + 0.5) / 256.0, 0.5));\n}\n\nmediump vec4 SamplePaletteLinear(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    // scale & offset uvs to integer values at texel centers\n    SDL_TEXCOORD_PRECISION vec2 uv_texels = uv * u_texel_size.zw + 0.5;\n\n    // get uvs for the center of the 4 surrounding texels by flooring\n    SDL_TEXCOORD_PRECISION vec4 uv_min_max = vec4((floor(uv_texels) - 0.5) * u_texel_size.xy, (floor(uv_texels) + 0.5) * u_texel_size.xy);\n\n    // blend factor\n    SDL_TEXCOORD_PRECISION vec2 uv_frac = fract(uv_texels);\n\n    // sample all 4 texels\n    mediump vec4 texelA = SamplePaletteNearest(uv_min_max.xy);\n    mediump vec4 texelB = SamplePaletteNearest(uv_min_max.xw);\n    mediump vec4 texelC = SamplePaletteNearest(uv_min_max.zy);\n    mediump vec4 texelD = SamplePaletteNearest(uv_min_max.zw);\n\n    // bilinear interpolation\n    return mix(mix(texelA, texelB, uv_frac.y), mix(texelC, texelD, uv_frac.y), uv_frac.x);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = SamplePaletteNearest(v_texCoord);\n    gl_FragColor = vec4(color.b, color.g, color.r, color.a);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 6:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_palette;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 SamplePaletteNearest(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    mediump float index = texture2D(u_texture, uv).r * 255.0;\n    return texture2D(u_palette, vec2((index + 0.5) / 256.0, 0.5));\n}\n\nmediump vec4 SamplePaletteLinear(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    // scale & offset uvs to integer values at texel centers\n    SDL_TEXCOORD_PRECISION vec2 uv_texels = uv * u_texel_size.zw + 0.5;\n\n    // get uvs for the center of the 4 surrounding texels by flooring\n    SDL_TEXCOORD_PRECISION vec4 uv_min_max = vec4((floor(uv_texels) - 0.5) * u_texel_size.xy, (floor(uv_texels) + 0.5) * u_texel_size.xy);\n\n    // blend factor\n    SDL_TEXCOORD_PRECISION vec2 uv_frac = fract(uv_texels);\n\n    // sample all 4 texels\n    mediump vec4 texelA = SamplePaletteNearest(uv_min_max.xy);\n    mediump vec4 texelB = SamplePaletteNearest(uv_min_max.xw);\n    mediump vec4 texelC = SamplePaletteNearest(uv_min_max.zy);\n    mediump vec4 texelD = SamplePaletteNearest(uv_min_max.zw);\n\n    // bilinear interpolation\n    return mix(mix(texelA, texelB, uv_frac.y), mix(texelC, texelD, uv_frac.y), uv_frac.x);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = SamplePaletteLinear(v_texCoord);\n    gl_FragColor = vec4(color.b, color.g, color.r, color.a);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 7:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_palette;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 SamplePaletteNearest(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    mediump float index = texture2D(u_texture, uv).r * 255.0;\n    return texture2D(u_palette, vec2((index + 0.5) / 256.0, 0.5));\n}\n\nmediump vec4 SamplePaletteLinear(SDL_TEXCOORD_PRECISION vec2 uv)\n{\n    // scale & offset uvs to integer values at texel centers\n    SDL_TEXCOORD_PRECISION vec2 uv_texels = uv * u_texel_size.zw + 0.5;\n\n    // get uvs for the center of the 4 surrounding texels by flooring\n    SDL_TEXCOORD_PRECISION vec4 uv_min_max = vec4((floor(uv_texels) - 0.5) * u_texel_size.xy, (floor(uv_texels) + 0.5) * u_texel_size.xy);\n\n    // blend factor\n    SDL_TEXCOORD_PRECISION vec2 uv_frac = fract(uv_texels);\n\n    // sample all 4 texels\n    mediump vec4 texelA = SamplePaletteNearest(uv_min_max.xy);\n    mediump vec4 texelB = SamplePaletteNearest(uv_min_max.xw);\n    mediump vec4 texelC = SamplePaletteNearest(uv_min_max.zy);\n    mediump vec4 texelD = SamplePaletteNearest(uv_min_max.zw);\n\n    // bilinear interpolation\n    return mix(mix(texelA, texelB, uv_frac.y), mix(texelC, texelD, uv_frac.y), uv_frac.x);\n}\n\nmediump vec4 GetPixelArtSample(vec2 uv)\n{\n    return texture2D(u_texture, uv);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = SamplePaletteNearest(v_texCoord);\n    gl_FragColor = vec4(color.b, color.g, color.r, color.a);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 8:

    return 

    "uniform sampler2D u_texture;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec4 color = texture2D(u_texture, v_texCoord);\n    gl_FragColor = vec4(color.b, color.g, color.r, 1.0);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 9:

    return 

    "uniform sampler2D u_texture;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 GetPixelArtSample(vec2 uv)\n{\n    return texture2D(u_texture, uv);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = GetPixelArtSample(v_texCoord);\n    gl_FragColor = vec4(color.b, color.g, color.r, 1.0);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 10:

    return 

    "uniform sampler2D u_texture;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec4 color = texture2D(u_texture, v_texCoord);\n    gl_FragColor = vec4(color.r, color.g, color.b, 1.0);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 0xb:

    return 

    "uniform sampler2D u_texture;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 GetPixelArtSample(vec2 uv)\n{\n    return texture2D(u_texture, uv);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = GetPixelArtSample(v_texCoord);\n    gl_FragColor = vec4(color.r, color.g, color.b, 1.0);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 0xc:

    return 

    "uniform sampler2D u_texture;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec4 color = texture2D(u_texture, v_texCoord);\n    gl_FragColor = vec4(color.b, color.g, color.r, color.a);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 0xd:

    return 

    "uniform sampler2D u_texture;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 GetPixelArtSample(vec2 uv)\n{\n    return texture2D(u_texture, uv);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = GetPixelArtSample(v_texCoord);\n    gl_FragColor = vec4(color.b, color.g, color.r, color.a);\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 0xe:

    return 

    "uniform sampler2D u_texture;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec4 color = texture2D(u_texture, v_texCoord);\n    gl_FragColor = color;\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 0xf:

    return 

    "uniform sampler2D u_texture;\nuniform mediump vec4 u_texel_size;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\nmediump vec4 GetPixelArtSample(vec2 uv)\n{\n    return texture2D(u_texture, uv);\n}\n\n\nvoid main()\n{\n    mediump vec4 color = GetPixelArtSample(v_texCoord);\n    gl_FragColor = color;\n    gl_FragColor *= v_color;\n}\n"

    ;

  case 0x10:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_texture_u;\nuniform sampler2D u_texture_v;\nuniform vec3 u_offset;\nuniform mat3 u_matrix;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec3 yuv;\n    lowp vec3 rgb;\n\n    // Get the YUV values \n    yuv.x = texture2D(u_texture,   v_texCoord).r;\n    yuv.y = texture2D(u_texture_u, v_texCoord).r;\n    yuv.z = texture2D(u_texture_v, v_texCoord).r;\n\n    // Do the color transform \n    yuv += u_offset;\n    rgb = yuv * u_matrix;\n\n    // That was easy. :) \n    gl_FragColor = vec4(rgb, 1);\n    gl_FragColor *= v_color;\n}"

    ;

  case 0x11:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_texture_u;\nuniform sampler2D u_texture_v;\nuniform vec3 u_offset;\nuniform mat3 u_matrix;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec3 yuv;\n    lowp vec3 rgb;\n\n    // Get the YUV values \n    yuv.x = texture2D(u_texture,   v_texCoord).r;\n    yuv.yz = texture2D(u_texture_u, v_texCoord).ra;\n\n    // Do the color transform \n    yuv += u_offset;\n    rgb = yuv * u_matrix;\n\n    // That was easy. :) \n    gl_FragColor = vec4(rgb, 1);\n    gl_FragColor *= v_color;\n}"

    ;

  case 0x12:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_texture_u;\nuniform sampler2D u_texture_v;\nuniform vec3 u_offset;\nuniform mat3 u_matrix;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec3 yuv;\n    lowp vec3 rgb;\n\n    // Get the YUV values \n    yuv.x = texture2D(u_texture,   v_texCoord).r;\n    yuv.yz = texture2D(u_texture_u, v_texCoord).rg;\n\n    // Do the color transform \n    yuv += u_offset;\n    rgb = yuv * u_matrix;\n\n    // That was easy. :) \n    gl_FragColor = vec4(rgb, 1);\n    gl_FragColor *= v_color;\n}"

    ;

  case 0x13:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_texture_u;\nuniform sampler2D u_texture_v;\nuniform vec3 u_offset;\nuniform mat3 u_matrix;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec3 yuv;\n    lowp vec3 rgb;\n\n    // Get the YUV values \n    yuv.x = texture2D(u_texture,   v_texCoord).r;\n    yuv.yz = texture2D(u_texture_u, v_texCoord).ar;\n\n    // Do the color transform \n    yuv += u_offset;\n    rgb = yuv * u_matrix;\n\n    // That was easy. :) \n    gl_FragColor = vec4(rgb, 1);\n    gl_FragColor *= v_color;\n}"

    ;

  case 0x14:

    return 

    "uniform sampler2D u_texture;\nuniform sampler2D u_texture_u;\nuniform sampler2D u_texture_v;\nuniform vec3 u_offset;\nuniform mat3 u_matrix;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    mediump vec3 yuv;\n    lowp vec3 rgb;\n\n    // Get the YUV values \n    yuv.x = texture2D(u_texture,   v_texCoord).r;\n    yuv.yz = texture2D(u_texture_u, v_texCoord).gr;\n\n    // Do the color transform \n    yuv += u_offset;\n    rgb = yuv * u_matrix;\n\n    // That was easy. :) \n    gl_FragColor = vec4(rgb, 1);\n    gl_FragColor *= v_color;\n}"

    ;

  case 0x15:

    return 

    "uniform samplerExternalOES u_texture;\nvarying mediump vec4 v_color;\nvarying SDL_TEXCOORD_PRECISION vec2 v_texCoord;\n\nvoid main()\n{\n    gl_FragColor = texture2D(u_texture, v_texCoord);\n    gl_FragColor *= v_color;\n}\n"

    ;

  default:

    return (char *)0x0;

  }

}




