// Address: 0x14015cef0
// Ghidra name: FUN_14015cef0
// ============ 0x14015cef0 FUN_14015cef0 (size=551) ============


undefined8 FUN_14015cef0(longlong param_1,undefined8 *param_2)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  longlong lVar5;

  code *pcVar6;

  int iVar7;

  undefined4 local_58;

  int iStack_54;

  undefined1 local_48 [64];

  

  FUN_14015fda0();

  if ((*(char *)(param_1 + 0xc0) != '\0') || (iVar2 = FUN_140138fe0(param_1 + 0x90), iVar2 != 0)) {

    return 1;

  }

  *(undefined8 *)(param_1 + 0x18) = DAT_1403fc0d0;

  *(undefined8 *)(param_1 + 0x20) = DAT_1403fc0d8;

  *(undefined8 *)(param_1 + 0x28) = DAT_1403fc0e0;

  *(undefined8 *)(param_1 + 0x30) = DAT_1403fc0e8;

  *(undefined8 *)(param_1 + 0x38) = DAT_1403fc0f0;

  *(undefined8 *)(param_1 + 0x40) = DAT_1403fc0f8;

  if (param_2 == (undefined8 *)0x0) {

    param_2 = (undefined8 *)(param_1 + 0x78);

  }

  uVar4 = *param_2;

  iVar2 = *(int *)(param_2 + 1);

  FUN_14015d2e0(*(undefined1 *)(param_1 + 0x94));

  local_58 = (undefined4)uVar4;

  iStack_54 = (int)((ulonglong)uVar4 >> 0x20);

  iVar7 = 2 - (uint)(*(char *)(param_1 + 0x94) != '\0');

  if ((byte)uVar4 < 0x11) {

    local_58 = 0x8010;

  }

  *(undefined4 *)(param_1 + 0x60) = local_58;

  if (iStack_54 < iVar7) {

    iStack_54 = iVar7;

  }

  *(int *)(param_1 + 100) = iStack_54;

  if (iVar2 < 0xac44) {

    iVar2 = 0xac44;

  }

  *(int *)(param_1 + 0x68) = iVar2;

  uVar3 = FUN_14015e620();

  *(undefined4 *)(param_1 + 0x84) = uVar3;

  FUN_14015fd50(param_1);

  *(undefined1 *)(param_1 + 0xc0) = 1;

  cVar1 = (*DAT_1403fc0b8)(param_1);

  if (cVar1 != '\0') {

    FUN_14015fd50(param_1);

    iVar2 = *(int *)(param_1 + 0xb0);

    uVar4 = FUN_14017fc90();

    lVar5 = FUN_140190080(uVar4,(longlong)iVar2);

    *(longlong *)(param_1 + 0x98) = lVar5;

    if (lVar5 != 0) {

      if (*(int *)(param_1 + 0x60) != 0x8120) {

        iVar2 = *(int *)(param_1 + 0xb0);

        uVar4 = FUN_14017fc90();

        lVar5 = FUN_140190080(uVar4,(longlong)iVar2);

        *(longlong *)(param_1 + 0xa0) = lVar5;

        if (lVar5 == 0) goto LAB_14015d0e9;

      }

      if (DAT_1403fc120 != '\0') {

        return 1;

      }

      FUN_14015e5c0(param_1,local_48,0x40);

      pcVar6 = FUN_14015d280;

      if (*(char *)(param_1 + 0x94) != '\0') {

        pcVar6 = FUN_14015d380;

      }

      lVar5 = FUN_140163260(pcVar6,local_48,param_1,FUN_1402cfa08,FUN_1402cfae8);

      *(longlong *)(param_1 + 0xb8) = lVar5;

      if (lVar5 != 0) {

        return 1;

      }

      FUN_14015c2e0(param_1);

      uVar4 = FUN_14012e850("Couldn\'t create audio thread");

      return uVar4;

    }

  }

LAB_14015d0e9:

  FUN_14015c2e0(param_1);

  return 0;

}




