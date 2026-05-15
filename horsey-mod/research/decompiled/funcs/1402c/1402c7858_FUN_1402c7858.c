// Address: 0x1402c7858
// Ghidra name: FUN_1402c7858
// ============ 0x1402c7858 FUN_1402c7858 (size=182) ============


void FUN_1402c7858(void)



{

  code *pcVar1;

  undefined4 *puVar2;

  char cVar3;

  int iVar4;

  undefined4 uVar5;

  

  FUN_1402e7d3c(2);

  iVar4 = FUN_1402c7f40();

  _set_fmode(iVar4);

  uVar5 = FUN_1400248b0();

  puVar2 = (undefined4 *)FUN_1402e816c();

  *puVar2 = uVar5;

  cVar3 = __scrt_initialize_onexit_tables(1);

  if (cVar3 != '\0') {

    FUN_1402c7f90();

    atexit(FUN_1402c7fcc);

    uVar5 = FUN_14000c580();

    iVar4 = FUN_1402e73e8(uVar5);

    if (iVar4 == 0) {

      FUN_1402c7f48();

      iVar4 = FUN_1402c7f74();

      if (iVar4 != 0) {

        FUN_1402e7db0(FUN_1400248b0);

      }

      _guard_check_icall();

      _guard_check_icall();

      iVar4 = FUN_1400248b0();

      _configthreadlocale(iVar4);

      cVar3 = FUN_140018e60();

      if (cVar3 != '\0') {

        thunk_FUN_1402e7568();

      }

      FUN_1400248b0();

      iVar4 = thunk_FUN_1400248b0();

      if (iVar4 == 0) {

        return;

      }

    }

  }

  FUN_1402c7c38(7);

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}




