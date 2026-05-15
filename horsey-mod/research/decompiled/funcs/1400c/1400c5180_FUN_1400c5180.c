// Address: 0x1400c5180
// Ghidra name: FUN_1400c5180
// ============ 0x1400c5180 FUN_1400c5180 (size=823) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400c5180(undefined8 param_1,int *param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  size_t sVar4;

  

  iVar1 = *param_2;

  if (iVar1 == 0x100) {

    DAT_1403f3350 = 1;

    return;

  }

  if (iVar1 == 0x303) {

    sVar4 = strlen(*(char **)(param_2 + 6));

    FUN_140027f50(&DAT_1403d9e80,*(undefined8 *)(param_2 + 6),sVar4);

    return;

  }

  if (iVar1 == 0x300) {

    if (*(char *)((longlong)param_2 + 0x25) == '\0') {

      uVar2 = param_2[7];

      uVar3 = param_2[6];

      if (uVar2 == 0x4000003d) {

        if ((*(ushort *)(param_2 + 8) & 0x300) != 0) {

          DAT_1403f3350 = 1;

        }

      }

      else if ((uVar2 == 0xd) && ((*(ushort *)(param_2 + 8) & 0x300) != 0)) {

        DAT_1403f3352 = 1;

      }

      if ((*(byte *)(param_2 + 8) & 0xc0) != 0) {

        DAT_1403ed4c1 = 1;

      }

      if ((*(byte *)(param_2 + 8) & 3) != 0) {

        DAT_1403ed4c2 = 1;

      }

      if (uVar2 < 0x80) {

        (&DAT_1403ed4d0)[(int)uVar2] = 1;

        (&DAT_1403ed5d0)[(int)uVar2] = 1;

        (&DAT_1403ed550)[(int)uVar2] = 0;

      }

      if (uVar3 < 0x100) {

        DAT_1403ed4c3 = (undefined1)uVar3;

        (&DAT_1403ed650)[(int)uVar3] = 1;

        (&DAT_1403ed850)[(int)uVar3] = 1;

        (&DAT_1403ed750)[(int)uVar3] = 0;

        return;

      }

    }

  }

  else if (iVar1 == 0x301) {

    if (*(char *)((longlong)param_2 + 0x25) == '\0') {

      uVar2 = param_2[7];

      if (uVar2 < 0x80) {

        (&DAT_1403ed550)[(int)uVar2] = (&DAT_1403ed4d0)[(int)uVar2];

        (&DAT_1403ed4d0)[(int)uVar2] = 0;

        (&DAT_1403ed5d0)[(int)uVar2] = 0;

      }

      uVar2 = param_2[6];

      if (uVar2 < 0x100) {

        (&DAT_1403ed750)[(int)uVar2] = (&DAT_1403ed650)[(int)uVar2];

        (&DAT_1403ed650)[(int)uVar2] = 0;

        (&DAT_1403ed850)[(int)uVar2] = 0;

        return;

      }

    }

  }

  else if (iVar1 == 0x400) {

    if (DAT_1403da600 == -1) {

      _DAT_1403ed980 = (int)(float)param_2[7];

      _DAT_1403ed984 = (int)(float)param_2[7];

      _DAT_1403ed988 = (int)(float)param_2[8];

      _DAT_1403ed98c = (int)(float)param_2[8];

      return;

    }

  }

  else if (iVar1 == 0x401) {

    if (DAT_1403da600 == -1) {

      _DAT_1403ed980 = (int)(float)param_2[7];

      _DAT_1403ed988 = (int)(float)param_2[8];

      if ((char)param_2[6] == '\x01') {

        DAT_1403ed958 = 1;

        DAT_1403ed960 = 1;

        return;

      }

      if ((char)param_2[6] == '\x03') {

        _DAT_1403ed95c = 1;

        DAT_1403ed964 = 1;

        return;

      }

    }

  }

  else if (iVar1 == 0x402) {

    if ((char)param_2[6] == '\x01') {

      DAT_1403ed958 = 0;

      DAT_1403ed968 = 1;

      return;

    }

    if ((char)param_2[6] == '\x03') {

      _DAT_1403ed95c = 0;

      DAT_1403ed96c = 1;

      return;

    }

  }

  else if (iVar1 == 0x403) {

    if (0.0 < (float)param_2[7]) {

      DAT_1403ed89b = 1;

      return;

    }

    if ((float)param_2[7] < 0.0) {

      DAT_1403ed89e = 1;

      return;

    }

  }

  else {

    if (iVar1 == 0x20e) {

      DAT_1403f3351 = 1;

      return;

    }

    if (iVar1 == 0x20f) {

      DAT_1403f3351 = 0;

      return;

    }

    if (iVar1 == 0x206) {

      DAT_1403d9e60 = param_2[5];

      DAT_1403d9e64 = param_2[6];

      FUN_14006fd60();

      if (DAT_1403d950c == '\0') {

        DAT_1403d9518 = param_2[5];

        DAT_1403d951c = param_2[6];

        return;

      }

    }

    else if ((iVar1 == 0x205) && (DAT_1403d950c == '\0')) {

      SDL_GetWindowPosition(param_1,&DAT_1403d9510,&DAT_1403d9514);

      return;

    }

  }

  return;

}




