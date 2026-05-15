// Address: 0x140206640
// Ghidra name: FUN_140206640
// ============ 0x140206640 FUN_140206640 (size=264) ============


undefined8

FUN_140206640(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined8 param_4)



{

  char cVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  uVar2 = FUN_140206820();

  if ((char)uVar2 != '\0') {

    cVar1 = FUN_140207fa0(param_1,param_2,param_3,param_4);

    if (((((cVar1 != '\0') || (lVar3 = thunk_FUN_1402c9340(param_4,&DAT_14034fe14), lVar3 != 0)) ||

         (lVar3 = thunk_FUN_1402c9340(param_4,"X-Box"), lVar3 != 0)) ||

        (lVar3 = thunk_FUN_1402c9340(param_4,&DAT_14034fe24), lVar3 != 0)) &&

       (cVar1 = FUN_1402086c0(), cVar1 != '\0')) {

      FUN_1402087d0();

      FUN_140207ad0();

    }

    FUN_140159d30();

    for (lVar3 = DAT_1403fd198; uVar2 = 0, lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0xb8)) {

      if (((*(short *)(lVar3 + 0x20) != 0x37d7) && (*(longlong *)(lVar3 + 0x68) != 0)) &&

         (cVar1 = FUN_140208080(param_1,param_2,lVar3), cVar1 != '\0')) {

        uVar2 = 1;

        break;

      }

    }

    FUN_14015bb10();

  }

  return uVar2;

}




