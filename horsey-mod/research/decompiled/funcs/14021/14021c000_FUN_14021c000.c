// Address: 0x14021c000
// Ghidra name: FUN_14021c000
// ============ 0x14021c000 FUN_14021c000 (size=151) ============


bool FUN_14021c000(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  bool bVar4;

  

  bVar4 = false;

  lVar1 = FUN_14021c4a0();

  if (lVar1 != 0) {

    lVar2 = FUN_14012c130(lVar1,&DAT_14039be7c);

    if (lVar2 != 0) {

      lVar3 = FUN_14012c730(lVar2,param_3,param_4);

      if (lVar3 != param_4) {

        FUN_14012e850("File length did not exactly match the destination length");

      }

      bVar4 = lVar3 == param_4;

      FUN_14012bd50(lVar2);

    }

    FUN_1401841e0(lVar1);

  }

  return bVar4;

}




