// Address: 0x1401777e0
// Ghidra name: FUN_1401777e0
// ============ 0x1401777e0 FUN_1401777e0 (size=121) ============


void FUN_1401777e0(void)



{

  longlong lVar1;

  int iVar2;

  

  iVar2 = FUN_14017ec60(0x8000);

  if (iVar2 != 0) {

    FUN_140177410();

    for (lVar1 = DAT_1403fc480; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x70)) {

      (**(code **)(*(longlong *)(lVar1 + 0x58) + 0x40))(lVar1);

    }

    (**(code **)(PTR_PTR_1403e2870 + 0x10))();

    FUN_140177750();

    return;

  }

  return;

}




