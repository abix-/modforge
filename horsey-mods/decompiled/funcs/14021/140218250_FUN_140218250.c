// Address: 0x140218250
// Ghidra name: FUN_140218250
// ============ 0x140218250 FUN_140218250 (size=223) ============


undefined1

FUN_140218250(longlong *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

             longlong param_5)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  

  if (param_5 != 0) {

    lVar3 = param_1[1];

    if (lVar3 == 0) {

      lVar3 = FUN_140217650();

      if (lVar3 == 0) {

        return 0;

      }

      *param_1 = lVar3;

      param_1[1] = lVar3;

    }

    else {

      cVar1 = FUN_14015da30(lVar3,param_2,*(undefined8 *)(lVar3 + 0x10),param_3);

      if (cVar1 == '\0') {

        FUN_140217780(lVar3);

      }

    }

    lVar2 = FUN_1402183a0(lVar3,param_4,param_5);

    param_4 = param_4 + lVar2;

    param_5 = param_5 - lVar2;

    while (param_5 != 0) {

      lVar2 = FUN_140217650(param_1,param_2,param_3);

      if (lVar2 == 0) {

        return 0;

      }

      *(longlong *)(lVar3 + 0x20) = lVar2;

      param_1[1] = lVar2;

      lVar3 = FUN_1402183a0(lVar2,param_4,param_5);

      param_4 = param_4 + lVar3;

      param_5 = param_5 - lVar3;

      lVar3 = lVar2;

    }

  }

  return 1;

}




