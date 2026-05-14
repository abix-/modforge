// Address: 0x14017f5b0
// Ghidra name: FUN_14017f5b0
// ============ 0x14017f5b0 FUN_14017f5b0 (size=643) ============


uint FUN_14017f5b0(void)



{

  bool bVar1;

  char cVar2;

  uint uVar3;

  char *_Str;

  char *pcVar4;

  size_t sVar5;

  uint uVar6;

  char *pcVar7;

  

  uVar6 = 0xffffffff;

  _Str = (char *)FUN_140142960("SDL_CPU_FEATURE_MASK");

  if (_Str != (char *)0x0) {

    cVar2 = *_Str;

    while (cVar2 != '\0') {

      pcVar4 = (char *)thunk_FUN_1402c9190(_Str,0x2c);

      bVar1 = true;

      if (pcVar4 == (char *)0x0) {

        sVar5 = strlen(_Str);

        pcVar4 = _Str + sVar5;

        pcVar7 = pcVar4;

      }

      else {

        pcVar7 = pcVar4 + 1;

      }

      if (*_Str == '+') {

LAB_14017f62b:

        _Str = _Str + 1;

      }

      else if (*_Str == '-') {

        bVar1 = false;

        goto LAB_14017f62b;

      }

      cVar2 = FUN_14017ff00(&DAT_14030dbd4,_Str,pcVar4);

      if (cVar2 == '\0') {

        cVar2 = FUN_14017ff00("altivec",_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 1;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_140337770,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 2;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_140337774,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 4;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_140337778,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 8;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_140337780,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x10;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00("sse41",_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x20;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00("sse42",_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x40;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_140337798,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x80;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_14033779c,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x100;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00("avx512f",_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x400;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00("arm-simd",_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x800;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_1403377bc,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x200;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_1403377c4,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x1000;

          goto LAB_14017f7fd;

        }

        cVar2 = FUN_14017ff00(&DAT_1403377c8,_Str,pcVar4);

        if (cVar2 != '\0') {

          uVar3 = 0x2000;

          goto LAB_14017f7fd;

        }

      }

      else {

        uVar3 = 0xffffffff;

LAB_14017f7fd:

        if (bVar1) {

          uVar6 = uVar6 | uVar3;

        }

        else {

          uVar6 = uVar6 & ~uVar3;

        }

      }

      _Str = pcVar7;

      cVar2 = *pcVar7;

    }

  }

  return uVar6;

}




