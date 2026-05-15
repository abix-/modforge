// Address: 0x14017d280
// Ghidra name: FUN_14017d280
// ============ 0x14017d280 FUN_14017d280 (size=152) ============


undefined4 FUN_14017d280(undefined4 param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_res10 [2];

  

  if (param_2 - 1U < 0xc) {

    if (0 < param_3) {

      iVar1 = FUN_14017d3c0();

      if (param_3 <= iVar1) {

        FUN_14017cec0(param_1,param_2,param_3,local_res10,0);

        return local_res10[0];

      }

    }

    uVar2 = FUN_14017d3c0(param_1,param_2);

    FUN_14012e850("Day out of range [1-%i], requested: %i",uVar2,param_2);

  }

  else {

    FUN_14012e850("Month out of range [1-12], requested: %i");

  }

  return 0xffffffff;

}




