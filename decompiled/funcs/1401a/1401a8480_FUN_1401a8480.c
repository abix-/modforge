// Address: 0x1401a8480
// Ghidra name: FUN_1401a8480
// ============ 0x1401a8480 FUN_1401a8480 (size=268) ============


void FUN_1401a8480(undefined8 param_1,undefined8 param_2,int param_3)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  int iVar4;

  

  if (param_3 != 0) {

    FUN_1401a8b60(param_1,param_3,param_2,0,1);

    FUN_14017cab0(DAT_1403fcd48);

    lVar3 = FUN_1401a8110(param_3);

    if (lVar3 != 0) {

      FUN_1401841e0(*(undefined8 *)(lVar3 + 8));

      lVar2 = DAT_1403fcd50;

      lVar3 = (lVar3 - DAT_1403fcd50) / 6 + (lVar3 - DAT_1403fcd50 >> 0x3f);

      iVar4 = (int)(lVar3 >> 4) - (int)(lVar3 >> 0x3f);

      iVar1 = DAT_1403fcd44 + -1;

      if (iVar4 < iVar1) {

        FUN_1402f8e20((longlong)iVar4 * 0x60 + DAT_1403fcd50,

                      (longlong)(iVar4 + 1) * 0x60 + DAT_1403fcd50,

                      (longlong)((DAT_1403fcd44 - iVar4) + -1) * 0x60);

      }

      DAT_1403fcd44 = iVar1;

      if (iVar1 == 0) {

        FUN_1401841e0(lVar2);

        DAT_1403fcd50 = 0;

      }

      else {

        lVar3 = FUN_140184230(lVar2,(longlong)iVar1 * 0x60);

        if (lVar3 != 0) {

          DAT_1403fcd50 = lVar3;

        }

      }

    }

    FUN_14017cae0(DAT_1403fcd48);

  }

  return;

}




