// Address: 0x140301104
// Ghidra name: FUN_140301104
// ============ 0x140301104 FUN_140301104 (size=86) ============


void FUN_140301104(void)



{

  undefined8 *puVar1;

  longlong lVar2;

  

  while (puVar1 = DAT_1403fe438, DAT_1403fe438 != (undefined8 *)0x0) {

    DAT_1403fe438 = (undefined8 *)*DAT_1403fe438;

    lVar2 = (*(code *)PTR__guard_dispatch_icall_140302c68)();

    if (lVar2 != 0) {

      (*(code *)PTR__guard_dispatch_icall_140302c68)(lVar2,1);

    }

    thunk_FUN_1402e9a80(puVar1);

  }

  return;

}




