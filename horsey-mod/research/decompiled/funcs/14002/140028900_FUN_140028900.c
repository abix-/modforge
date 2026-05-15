// Address: 0x140028900
// Ghidra name: FUN_140028900
// ============ 0x140028900 FUN_140028900 (size=201) ============


byte * FUN_140028900(byte *param_1,undefined8 param_2)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  

  FUN_140027f50(param_2,&DAT_14039bcb9,0);

  if (param_1 == (byte *)0x0) {

    FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x197);

  }

  else {

    bVar1 = *param_1;

    if ((bVar1 != 0) &&

       (((pbVar3 = param_1, 0x7e < bVar1 || (iVar2 = isalpha((uint)bVar1), iVar2 != 0)) ||

        (*param_1 == 0x5f)))) {

      while (bVar1 = *pbVar3, bVar1 != 0) {

        if ((((bVar1 < 0x7f) && (iVar2 = isalnum((uint)bVar1), iVar2 == 0)) &&

            ((bVar1 = *pbVar3, bVar1 != 0x5f && ((1 < (byte)(bVar1 - 0x2d) && (bVar1 != 0x3a))))))

           || (pbVar3 = pbVar3 + 1, pbVar3 == (byte *)0x0)) break;

      }

      if (0 < (longlong)pbVar3 - (longlong)param_1) {

        FUN_140027f50(param_2,param_1);

      }

      return pbVar3;

    }

  }

  return (byte *)0x0;

}




