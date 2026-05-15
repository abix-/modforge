// Address: 0x140228540
// Ghidra name: FUN_140228540
// ============ 0x140228540 FUN_140228540 (size=295) ============


/* WARNING: Removing unreachable block (ram,0x0001402285f0) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140228540(void)



{

  int iVar1;

  int iVar2;

  BOOL BVar3;

  int iVar4;

  longlong lVar5;

  undefined8 uVar6;

  int local_res8 [8];

  undefined1 local_18 [8];

  int local_10;

  

  lVar5 = FUN_1401611a0();

  if (*(code **)(lVar5 + 0x58) == FUN_140227940) {

    *(undefined **)(lVar5 + 0x60) = &DAT_1403fdc80;

  }

  _DAT_1403fdce0 = 0x20;

  _DAT_1403fdcd0 = 0;

  uRam00000001403fdcd8 = 0;

  iVar2 = FUN_1401a9950();

  _DAT_1403fdce4 = 0x5dc0000;

  if (iVar2 != 0) {

    _DAT_1403fdce4 = 0x4b00000;

  }

  uVar6 = FUN_14016dcf0();

  DAT_1403fdced = FUN_140181590(uVar6);

  DAT_1403fdcec = 0;

  local_res8[0] = 10;

  BVar3 = SystemParametersInfoW(0x70,0,local_res8,0);

  if (BVar3 != 0) {

    iVar2 = 0x14;

    if (local_res8[0] < 0x14) {

      iVar2 = local_res8[0];

    }

    if (iVar2 < 1) {

      local_res8[0] = 1;

      _DAT_1403fdce0 = 1;

    }

    else {

      iVar1 = iVar2 * 4 + -8;

      _DAT_1403fdce0 = iVar2 * 8 + -0x30;

      iVar4 = iVar2;

      if (iVar2 <= iVar1) {

        iVar4 = iVar1;

      }

      local_res8[0] = iVar2;

      if ((_DAT_1403fdce0 < iVar4) && (_DAT_1403fdce0 = iVar2, iVar2 <= iVar1)) {

        _DAT_1403fdce0 = iVar1;

      }

    }

  }

  BVar3 = SystemParametersInfoW(3,0,local_18,0);

  if ((BVar3 != 0) && (DAT_1403fdcec = local_10 != 0, local_10 != 0)) {

    FUN_140227710(local_res8[0],&DAT_1403fdc80,&DAT_1403fdca8);

  }

  return;

}




