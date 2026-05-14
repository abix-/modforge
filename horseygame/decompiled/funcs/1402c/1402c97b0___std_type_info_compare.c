// Address: 0x1402c97b0
// Ghidra name: __std_type_info_compare
// ============ 0x1402c97b0 __std_type_info_compare (size=39) ============


/* Library Function - Single Match

    __std_type_info_compare

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



uint __std_type_info_compare(longlong param_1,longlong param_2)



{

  byte bVar1;

  byte *pbVar2;

  longlong lVar3;

  

  if (param_1 != param_2) {

    pbVar2 = (byte *)(param_1 + 9);

    lVar3 = (param_2 + 9) - (longlong)pbVar2;

    do {

      bVar1 = *pbVar2;

      if (bVar1 != pbVar2[lVar3]) {

        return -(uint)(bVar1 < pbVar2[lVar3]) | 1;

      }

      pbVar2 = pbVar2 + 1;

    } while (bVar1 != 0);

  }

  return 0;

}




