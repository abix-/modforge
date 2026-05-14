// Address: 0x1402e1dc0
// Ghidra name: FUN_1402e1dc0
// ============ 0x1402e1dc0 FUN_1402e1dc0 (size=95) ============


undefined8 FUN_1402e1dc0(undefined8 param_1,int param_2)



{

  short sVar1;

  undefined8 local_res8 [4];

  

  if ((param_2 != 0) &&

     (local_res8[0] = param_1, sVar1 = FUN_1402f18e0(), param_1 = local_res8[0], sVar1 < 0)) {

    sVar1 = FUN_1402f1a00(local_res8,param_2);

    if (sVar1 == 0) {

      FUN_1402eb620(0x10);

      param_1 = local_res8[0];

    }

    else {

      param_1 = local_res8[0];

      if (sVar1 == 1) {

        FUN_1402eb620(8);

        return local_res8[0];

      }

    }

  }

  return param_1;

}




