// Address: 0x1401e2180
// Ghidra name: FUN_1401e2180
// ============ 0x1401e2180 FUN_1401e2180 (size=274) ============


void FUN_1401e2180(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x138);

  if (lVar1 != 0) {

    if (*(longlong **)(lVar1 + 8) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 8) + 0x10))();

      *(undefined8 *)(lVar1 + 8) = 0;

    }

    if (*(longlong **)(lVar1 + 0x10) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x10))();

      *(undefined8 *)(lVar1 + 0x10) = 0;

    }

    if (*(longlong **)(lVar1 + 0x18) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x18) + 0x10))();

      *(undefined8 *)(lVar1 + 0x18) = 0;

    }

    if (*(longlong **)(lVar1 + 0x20) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x10))();

      *(undefined8 *)(lVar1 + 0x20) = 0;

    }

    if (*(longlong **)(lVar1 + 0x40) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x40) + 0x10))();

      *(undefined8 *)(lVar1 + 0x40) = 0;

    }

    if (*(longlong **)(lVar1 + 0x48) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x10))();

      *(undefined8 *)(lVar1 + 0x48) = 0;

    }

    if (*(longlong **)(lVar1 + 0x50) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x50) + 0x10))();

      *(undefined8 *)(lVar1 + 0x50) = 0;

    }

    if (*(longlong **)(lVar1 + 0x58) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x58) + 0x10))();

      *(undefined8 *)(lVar1 + 0x58) = 0;

    }

    if (*(longlong **)(lVar1 + 0x68) != (longlong *)0x0) {

      (**(code **)(**(longlong **)(lVar1 + 0x68) + 0x10))();

      *(undefined8 *)(lVar1 + 0x68) = 0;

    }

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x70));

    FUN_1401841e0(lVar1);

    *(undefined8 *)(param_2 + 0x138) = 0;

  }

  return;

}




