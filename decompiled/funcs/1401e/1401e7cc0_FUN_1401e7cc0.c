// Address: 0x1401e7cc0
// Ghidra name: FUN_1401e7cc0
// ============ 0x1401e7cc0 FUN_1401e7cc0 (size=261) ============


void FUN_1401e7cc0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x138);

  if (lVar1 != 0) {

    FUN_1401e82f0(*(undefined8 *)(param_1 + 0x2e0));

    if (*(longlong **)(lVar1 + 8) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 8) + 0x10))();

      *(undefined8 *)(lVar1 + 8) = 0;

    }

    if (*(longlong **)(lVar1 + 0x38) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x38) + 0x10))();

      *(undefined8 *)(lVar1 + 0x38) = 0;

    }

    FUN_1401e7e30(param_1,*(undefined8 *)(lVar1 + 0x20));

    if (*(longlong **)(lVar1 + 0x58) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x58) + 0x10))();

      *(undefined8 *)(lVar1 + 0x58) = 0;

    }

    if (*(longlong **)(lVar1 + 0x78) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x78) + 0x10))();

      *(undefined8 *)(lVar1 + 0x78) = 0;

    }

    if (*(char *)(lVar1 + 0x50) != '\0') {

      FUN_1401e7e30(param_1,*(undefined8 *)(lVar1 + 0x70));

      FUN_1401e7e30(param_1,*(undefined8 *)(lVar1 + 0x90));

    }

    if (*(char *)(lVar1 + 0x98) != '\0') {

      FUN_1401e7e30(param_1,*(undefined8 *)(lVar1 + 0xa8));

    }

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0xb0));

    FUN_1401841e0(lVar1);

    *(undefined8 *)(param_2 + 0x138) = 0;

  }

  return;

}




