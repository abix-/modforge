// Address: 0x14017d320
// Ghidra name: FUN_14017d320
// ============ 0x14017d320 FUN_14017d320 (size=151) ============


undefined4 FUN_14017d320(undefined4 param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_res10 [2];

  

  if (param_2 - 1U < 0xc) {

    if (0 < param_3) {

      iVar1 = FUN_14017d3c0();

      if (param_3 <= iVar1) {

        FUN_14017cec0(param_1,param_2,param_3,0,local_res10);

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




