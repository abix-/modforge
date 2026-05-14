// Address: 0x1400289d0
// Ghidra name: FUN_1400289d0
// ============ 0x1400289d0 FUN_1400289d0 (size=751) ============


/* WARNING: Restarted to delay deadcode elimination for space: stack */



byte * FUN_1400289d0(byte *param_1,byte *param_2,int *param_3,int param_4)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  ulonglong uVar5;

  byte bVar6;

  uint uVar7;

  undefined **ppuVar8;

  int iVar9;

  longlong lVar10;

  byte local_58 [32];

  

  uVar7 = 0;

  *param_3 = 0;

  if ((param_1[1] != 0) && (param_1[1] == 0x23)) {

    if (param_1[2] != 0) {

      iVar9 = 1;

      if (param_1[2] == 0x78) {

        if (param_1[3] == 0) {

          return (byte *)0x0;

        }

        pcVar3 = (char *)FUN_1402c9190(param_1 + 3,0x3b);

        if (pcVar3 == (char *)0x0) {

          return (byte *)0x0;

        }

        if (*pcVar3 == '\0') {

          return (byte *)0x0;

        }

        lVar10 = (longlong)pcVar3 - (longlong)param_1;

        cVar1 = pcVar3[-1];

        while (cVar1 != 'x') {

          if ((byte)(cVar1 - 0x30U) < 10) {

            iVar2 = cVar1 + -0x30;

          }

          else if ((byte)(cVar1 + 0x9fU) < 6) {

            iVar2 = cVar1 + -0x57;

          }

          else {

            if (5 < (byte)(cVar1 + 0xbfU)) {

              return (byte *)0x0;

            }

            iVar2 = cVar1 + -0x37;

          }

          iVar2 = iVar2 * iVar9;

          iVar9 = iVar9 << 4;

          uVar7 = uVar7 + iVar2;

          cVar1 = pcVar3[-2];

          pcVar3 = pcVar3 + -1;

        }

      }

      else {

        pcVar3 = (char *)FUN_1402c9190(param_1 + 2,0x3b);

        if (pcVar3 == (char *)0x0) {

          return (byte *)0x0;

        }

        if (*pcVar3 == '\0') {

          return (byte *)0x0;

        }

        pcVar4 = pcVar3 + -1;

        lVar10 = (longlong)pcVar3 - (longlong)param_1;

        cVar1 = pcVar3[-1];

        while (cVar1 != '#') {

          if (9 < (byte)(cVar1 - 0x30U)) {

            return (byte *)0x0;

          }

          pcVar4 = pcVar4 + -1;

          iVar2 = (cVar1 + -0x30) * iVar9;

          iVar9 = iVar9 * 10;

          uVar7 = uVar7 + iVar2;

          cVar1 = *pcVar4;

        }

      }

      bVar6 = (byte)uVar7;

      if (param_4 != 1) {

        *param_2 = bVar6;

        *param_3 = 1;

        return param_1 + lVar10 + 1;

      }

      local_58[0] = 0;

      local_58[1] = 0;

      local_58[2] = 0;

      local_58[3] = 0;

      local_58[4] = 0;

      local_58[5] = 0;

      local_58[6] = 0;

      local_58[7] = 0;

      local_58[8] = 0xc0;

      local_58[9] = 0;

      local_58[10] = 0;

      local_58[0xb] = 0;

      local_58[0xc] = 0xe0;

      local_58[0xd] = 0;

      local_58[0xe] = 0;

      local_58[0xf] = 0;

      local_58[0x10] = 0xf0;

      local_58[0x11] = 0;

      local_58[0x12] = 0;

      local_58[0x13] = 0;

      local_58[0x14] = 0xf8;

      local_58[0x15] = 0;

      local_58[0x16] = 0;

      local_58[0x17] = 0;

      local_58[0x18] = 0xfc;

      local_58[0x19] = 0;

      local_58[0x1a] = 0;

      local_58[0x1b] = 0;

      if (uVar7 < 0x80) {

        *param_3 = 1;

        *param_2 = bVar6;

        return param_1 + lVar10 + 1;

      }

      if (uVar7 < 0x800) {

        *param_3 = 2;

      }

      else {

        if (uVar7 < 0x10000) {

          *param_3 = 3;

        }

        else {

          if (0x1fffff < uVar7) {

            *param_3 = 0;

            return param_1 + lVar10 + 1;

          }

          *param_3 = 4;

          param_2[3] = bVar6 & 0x3f | 0x80;

          uVar7 = uVar7 >> 6;

        }

        bVar6 = (byte)uVar7;

        uVar7 = uVar7 >> 6;

        param_2[2] = bVar6 & 0x3f | 0x80;

      }

      param_2[1] = (byte)uVar7 & 0x3f | 0x80;

      *param_2 = (byte)(uVar7 >> 6) | local_58[(longlong)*param_3 * 4];

      return param_1 + lVar10 + 1;

    }

  }

  ppuVar8 = &PTR_DAT_1403e9700;

  do {

    iVar9 = strncmp(*ppuVar8,(char *)param_1,(ulonglong)*(uint *)(ppuVar8 + 1));

    if (iVar9 == 0) {

      lVar10 = (longlong)(int)uVar7;

      uVar5 = 0xffffffffffffffff;

      do {

        uVar5 = uVar5 + 1;

      } while ((&PTR_DAT_1403e9700)[lVar10 * 2][uVar5] != '\0');

      if (uVar5 != (uint)(&DAT_1403e9708)[lVar10 * 4]) {

        FID_conflict__assert

                  (L"strlen( entity[i].str ) == entity[i].strLength",

                   L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x207);

      }

      *param_2 = (&DAT_1403e970c)[lVar10 * 0x10];

      *param_3 = 1;

      return param_1 + (uint)(&DAT_1403e9708)[lVar10 * 4];

    }

    uVar7 = uVar7 + 1;

    ppuVar8 = ppuVar8 + 2;

  } while ((longlong)ppuVar8 < 0x1403e9750);

  *param_2 = *param_1;

  return param_1 + 1;

}




