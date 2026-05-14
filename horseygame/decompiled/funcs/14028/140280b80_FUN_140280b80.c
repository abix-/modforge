// Address: 0x140280b80
// Ghidra name: FUN_140280b80
// ============ 0x140280b80 FUN_140280b80 (size=201) ============


undefined8 FUN_140280b80(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  iVar2 = 0xf;

  *(undefined8 *)(lVar1 + 0x40) = 0;

  *(undefined8 *)(lVar1 + 0x48) = 0;

  *(undefined8 *)(lVar1 + 0x50) = 0;

  *(undefined8 *)(lVar1 + 0x58) = 0;

  *(undefined8 *)(lVar1 + 0x60) = 0;

  *(undefined8 *)(lVar1 + 0x68) = 0;

  *(undefined8 *)(lVar1 + 0x70) = 0;

  *(undefined8 *)(lVar1 + 0x78) = 0;

  *(undefined4 *)(param_2 + 0x70) = 0xf;

  if (*(char *)(lVar1 + 10) != '\0') {

    iVar2 = 0x11;

    *(undefined4 *)(param_2 + 0x70) = 0x11;

  }

  if (*(char *)(lVar1 + 0xb) != '\0') {

    iVar2 = iVar2 + 2;

    *(int *)(param_2 + 0x70) = iVar2;

  }

  if (*(char *)(lVar1 + 0xc) != '\0') {

    *(int *)(param_2 + 0x70) = iVar2 + 1;

  }

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  if (*(char *)(lVar1 + 0xd) != '\0') {

    *(undefined4 *)(param_2 + 0xe4) = 2;

  }

  if (*(char *)(lVar1 + 0xe) != '\0') {

    uVar3 = DAT_140380104;

    if (*(char *)(lVar1 + 0xd) != '\0') {

      uVar3 = DAT_14039ca60;

    }

    FUN_14015a190(param_2,2,uVar3);

    FUN_14015a190(param_2,1,uVar3);

  }

  return 1;

}




