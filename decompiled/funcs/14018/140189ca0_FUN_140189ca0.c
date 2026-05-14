// Address: 0x140189ca0
// Ghidra name: FUN_140189ca0
// ============ 0x140189ca0 FUN_140189ca0 (size=211) ============


ulonglong FUN_140189ca0(longlong param_1,undefined8 *param_2,undefined4 *param_3)



{

  int iVar1;

  ulonglong uVar2;

  ulonglong local_res8;

  

  if ((ulonglong)*(uint *)(param_1 + 4) != *(ulonglong *)(param_1 + 0x18)) {

    uVar2 = FUN_14018a0e0(param_1,*(ulonglong *)(param_1 + 0x18) /

                                  (ulonglong)*(ushort *)(param_1 + 0x30));

    *(ulonglong *)(param_1 + 0x58) = uVar2;

    if ((longlong)uVar2 < 0) {

      return uVar2 & 0xffffffffffffff00;

    }

  }

  local_res8 = *(ulonglong *)(param_1 + 0x58);

  if (local_res8 == 0) {

    *param_2 = 0;

    *param_3 = 0;

    uVar2 = 1;

  }

  else if ((*(short *)(param_1 + 0x22) == 1) && (*(short *)(param_1 + 0x32) == 0x18)) {

    uVar2 = FUN_140189b70(param_1,param_2,param_3);

  }

  else {

    iVar1 = FUN_14018a0b0(&local_res8,*(undefined2 *)(param_1 + 0x30));

    if ((iVar1 == 0) && (local_res8 < 0x100000000)) {

      *param_2 = *(undefined8 *)(param_1 + 0x10);

      *param_3 = (int)local_res8;

      *(undefined8 *)(param_1 + 0x10) = 0;

      *(undefined8 *)(param_1 + 0x18) = 0;

      uVar2 = 1;

    }

    else {

      uVar2 = FUN_14012e850("WAVE file too big");

    }

  }

  return uVar2;

}




