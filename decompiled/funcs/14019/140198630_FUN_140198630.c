// Address: 0x140198630
// Ghidra name: FUN_140198630
// ============ 0x140198630 FUN_140198630 (size=254) ============


ulonglong FUN_140198630(longlong param_1,longlong param_2,undefined8 param_3)



{

  byte bVar1;

  ulonglong uVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  

  if (param_1 == 0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140314094);

    return uVar2;

  }

  if (param_2 != 0) {

    bVar1 = 0;

    lVar3 = FUN_140198200(param_1,&DAT_1403376f4);

    if (lVar3 != 0) {

      *(undefined1 *)(lVar3 + 200) = 1;

      lVar4 = FUN_1401985f0(lVar3);

      if ((-1 < lVar4) && (lVar5 = FUN_1401841f0(lVar4 + 1), lVar5 != 0)) {

        *(undefined1 *)(lVar4 + lVar5) = 0;

        bVar1 = FUN_140198740(lVar3,lVar5,0,lVar4,param_2,param_3);

        if (bVar1 == 0) {

          FUN_1401841e0(lVar5);

        }

      }

      FUN_140198310(lVar3,0,param_2,param_3);

    }

    return (ulonglong)bVar1;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","queue");

  return uVar2;

}




