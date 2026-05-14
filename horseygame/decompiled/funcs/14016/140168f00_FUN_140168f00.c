// Address: 0x140168f00
// Ghidra name: FUN_140168f00
// ============ 0x140168f00 FUN_140168f00 (size=160) ============


undefined1 FUN_140168f00(longlong param_1,undefined8 *param_2,longlong param_3)



{

  int iVar1;

  undefined8 uVar2;

  char cVar3;

  undefined4 uVar4;

  

  cVar3 = FUN_14015da30(param_1 + 0x68,param_2,*(undefined8 *)(param_1 + 0x78),param_3);

  if (cVar3 == '\0') {

    uVar2 = *(undefined8 *)(param_1 + 0x60);

    uVar4 = FUN_140214350();

    cVar3 = FUN_1402181b0(uVar2,uVar4);

    if (cVar3 == '\0') {

      return 0;

    }

    if (param_3 == 0) {

      *(undefined8 *)(param_1 + 0x78) = 0;

    }

    else {

      iVar1 = *(int *)((longlong)param_2 + 4);

      *(longlong *)(param_1 + 0x78) = param_1 + 0x80;

      FUN_1402f8e20(param_1 + 0x80,param_3,(longlong)iVar1 << 2);

    }

    *(undefined8 *)(param_1 + 0x68) = *param_2;

    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 1);

  }

  return 1;

}




