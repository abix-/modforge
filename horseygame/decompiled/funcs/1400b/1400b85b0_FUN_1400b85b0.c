// Address: 0x1400b85b0
// Ghidra name: FUN_1400b85b0
// ============ 0x1400b85b0 FUN_1400b85b0 (size=167) ============


void FUN_1400b85b0(longlong param_1,longlong param_2,undefined4 param_3)



{

  int iVar1;

  undefined8 *puVar2;

  ulonglong uVar3;

  

  puVar2 = *(undefined8 **)(param_1 + 0x240);

  if (puVar2 != (undefined8 *)0x0) {

    (**(code **)*puVar2)(puVar2,1);

  }

  *(longlong *)(param_1 + 0x240) = param_2;

  *(undefined4 *)(param_1 + 0x238) = 1;

  iVar1 = *(int *)(param_2 + 0xc);

  uVar3 = FUN_14005cda0(param_2);

  if ((uVar3 & 0xfffffffb) != 0) {

    if ((*(char *)(param_1 + 0x205) == '\0') && (1 < iVar1 - 3U)) {

      *(int *)(param_1 + 0x20c) = *(int *)(param_1 + 0x20c) + 1;

    }

    else {

      *(undefined4 *)(param_1 + 0x20c) = 0;

    }

    *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(param_1 + 0x25c);

    *(undefined1 *)(param_1 + 0x205) = 0;

  }

  *(undefined4 *)(param_1 + 0x23c) = param_3;

  return;

}




