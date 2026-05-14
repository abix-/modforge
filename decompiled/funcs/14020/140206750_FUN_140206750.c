// Address: 0x140206750
// Ghidra name: FUN_140206750
// ============ 0x140206750 FUN_140206750 (size=194) ============


void FUN_140206750(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  _guard_check_icall();

  if (*(longlong **)(param_1 + 0x148) != (longlong *)0x0) {

    lVar1 = **(longlong **)(param_1 + 0x148);

    if (*(char *)(lVar1 + 0x99) != '\0') {

      FUN_140179b60(*(undefined8 *)(lVar1 + 0x78));

    }

    lVar3 = 3;

    do {

      iVar2 = FUN_140138fe0(lVar1 + 0x88);

      if (0 < iVar2) {

        FUN_1401492f0(10);

      }

      lVar3 = lVar3 + -1;

    } while (lVar3 != 0);

    if (*(char *)(lVar1 + 0x99) != '\0') {

      FUN_140179b40(*(undefined8 *)(lVar1 + 0x78));

    }

    (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x88))(lVar1,param_1);

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x148));

    *(undefined8 *)(param_1 + 0x148) = 0;

  }

  return;

}




