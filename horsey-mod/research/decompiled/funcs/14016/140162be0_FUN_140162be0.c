// Address: 0x140162be0
// Ghidra name: FUN_140162be0
// ============ 0x140162be0 FUN_140162be0 (size=182) ============


void FUN_140162be0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  

  lVar5 = FUN_1401611a0();

  lVar1 = *(longlong *)(lVar5 + 0x118);

  if (param_1 != lVar1) {

    if (lVar1 != 0) {

      if (*(longlong *)(lVar5 + 0x120) == lVar1) {

        *(undefined8 *)(lVar5 + 0x120) = 0;

      }

      *(undefined8 *)(lVar5 + 0x118) = 0;

      lVar4 = *(longlong *)(lVar5 + 0x110);

      lVar3 = 0;

      while (lVar2 = lVar4, lVar2 != 0) {

        if (lVar2 == lVar1) {

          if (lVar3 == 0) {

            *(undefined8 *)(lVar5 + 0x110) = *(undefined8 *)(lVar2 + 0x10);

          }

          else {

            *(undefined8 *)(lVar3 + 0x10) = *(undefined8 *)(lVar2 + 0x10);

          }

          break;

        }

        lVar3 = lVar2;

        lVar4 = *(longlong *)(lVar2 + 0x10);

      }

      if ((*(code **)(lVar5 + 0x28) == (code *)0x0) || (*(longlong *)(lVar1 + 8) == 0)) {

        FUN_1401841e0();

      }

      else {

        (**(code **)(lVar5 + 0x28))();

      }

    }

    *(longlong *)(lVar5 + 0x118) = param_1;

    if (*(longlong *)(lVar5 + 0x120) == 0) {

      FUN_140162b40(param_1);

    }

  }

  return;

}




