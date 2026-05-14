// Address: 0x14019b180
// Ghidra name: FUN_14019b180
// ============ 0x14019b180 FUN_14019b180 (size=128) ============


undefined1 FUN_14019b180(undefined8 param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined1 uVar3;

  char local_res10;

  char local_res11;

  char local_res12;

  char local_res13;

  

  uVar3 = 0;

  lVar1 = FUN_14012cba0();

  if (-1 < lVar1) {

    lVar2 = FUN_14012c730(param_1,&local_res10,4);

    if ((((lVar2 == 4) && (local_res10 == -0x77)) && (local_res11 == 'P')) && (local_res12 == 'N'))

    {

      uVar3 = 0;

      if (local_res13 == 'G') {

        uVar3 = 1;

      }

    }

    FUN_14012cb40(param_1,lVar1,0);

  }

  return uVar3;

}




