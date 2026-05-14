// Address: 0x1401873d0
// Ghidra name: FUN_1401873d0
// ============ 0x1401873d0 FUN_1401873d0 (size=114) ============


undefined1 FUN_1401873d0(undefined8 param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined1 uVar3;

  char local_res10;

  char local_res11;

  

  uVar3 = 0;

  lVar1 = FUN_14012cba0();

  if (-1 < lVar1) {

    lVar2 = FUN_14012c730(param_1,&local_res10,2);

    if ((lVar2 == 2) && (local_res10 == 'B')) {

      uVar3 = 0;

      if (local_res11 == 'M') {

        uVar3 = 1;

      }

    }

    FUN_14012cb40(param_1,lVar1,0);

  }

  return uVar3;

}




