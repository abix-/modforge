// Address: 0x14013e7b0
// Ghidra name: FUN_14013e7b0
// ============ 0x14013e7b0 FUN_14013e7b0 (size=152) ============


undefined8 FUN_14013e7b0(undefined4 param_1)



{

  longlong lVar1;

  undefined4 *puVar2;

  undefined8 local_res10 [3];

  undefined4 local_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  undefined1 local_38 [48];

  

  local_res10[0] = 0;

  FUN_140159d30();

  lVar1 = FUN_140140710(param_1,1);

  if (lVar1 != 0) {

    puVar2 = (undefined4 *)FUN_140158250(&local_48,param_1);

    local_48 = *puVar2;

    uStack_44 = puVar2[1];

    uStack_40 = puVar2[2];

    uStack_3c = puVar2[3];

    FUN_14017e050(&local_48,local_38,0x21);

    FUN_14012ee40(local_res10,"%s,%s,%s",local_38,*(undefined8 *)(lVar1 + 0x10),

                  *(undefined8 *)(lVar1 + 0x18));

  }

  FUN_14015bb10();

  return local_res10[0];

}




