// Address: 0x14017a950
// Ghidra name: FUN_14017a950
// ============ 0x14017a950 FUN_14017a950 (size=276) ============


longlong FUN_14017a950(int param_1)



{

  char cVar1;

  longlong lVar2;

  longlong local_res10 [3];

  

  lVar2 = (longlong)param_1;

  cVar1 = FUN_140163c40(&DAT_1403fc550);

  if (cVar1 != '\0') {

    DAT_1403fc568 = FUN_1401aaee0(0,1,&LAB_1401aa980,&LAB_1401aa9c0,&LAB_1401aafe0,0);

    if (DAT_1403fc568 == 0) {

      FUN_140163ab0(&DAT_1403fc550,0);

      return 0;

    }

    FUN_140163ab0(&DAT_1403fc550,1);

  }

  cVar1 = FUN_1401aaff0(DAT_1403fc568,lVar2,local_res10);

  if (cVar1 == '\0') {

    local_res10[0] = FUN_1401841f0(0x20);

    if (local_res10[0] != 0) {

      cVar1 = FUN_14017b920(local_res10[0],param_1);

      if (cVar1 != '\0') {

        cVar1 = FUN_1401ab100(DAT_1403fc568,lVar2,local_res10[0],0);

        if (cVar1 == '\0') {

          FUN_1401841e0(local_res10[0]);

          cVar1 = FUN_1401aaff0(DAT_1403fc568,lVar2,local_res10);

          if (cVar1 == '\0') {

            return 0;

          }

        }

        return local_res10[0];

      }

      FUN_1401841e0(local_res10[0]);

    }

    return 0;

  }

  return local_res10[0];

}




