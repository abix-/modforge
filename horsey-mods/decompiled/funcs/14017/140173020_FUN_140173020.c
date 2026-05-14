// Address: 0x140173020
// Ghidra name: FUN_140173020
// ============ 0x140173020 FUN_140173020 (size=148) ============


void FUN_140173020(void)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  

  if ((DAT_1403fc410 != 0) && (*(longlong *)(DAT_1403fc410 + 0x300) != 0)) {

    cVar2 = FUN_140139420(0x1000);

    if ((cVar2 == '\0') && (cVar2 = FUN_140139420(0x1001), cVar2 == '\0')) {

      uVar3 = 0;

    }

    else {

      uVar3 = 1;

    }

    for (lVar1 = *(longlong *)(DAT_1403fc410 + 0x348); lVar1 != 0;

        lVar1 = *(longlong *)(lVar1 + 0x1a0)) {

      (**(code **)(DAT_1403fc410 + 0x300))(lVar1,uVar3);

    }

  }

  return;

}




