// Address: 0x140141f40
// Ghidra name: FUN_140141f40
// ============ 0x140141f40 FUN_140141f40 (size=150) ============


ulonglong FUN_140141f40(undefined4 param_1,undefined *param_2)



{

  int iVar1;

  undefined8 *puVar2;

  ulonglong uVar3;

  longlong lVar4;

  undefined *puVar5;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  puVar2 = (undefined8 *)FUN_140158250(&local_18,param_1);

  local_28 = *puVar2;

  uStack_20 = puVar2[1];

  iVar1 = memcmp(&local_28,&DAT_1403fbf08,0x10);

  if (iVar1 == 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","instance_id");

    return uVar3;

  }

  FUN_140159d30();

  local_18 = (undefined4)local_28;

  uStack_14 = local_28._4_4_;

  uStack_10 = (undefined4)uStack_20;

  uStack_c = uStack_20._4_4_;

  puVar5 = &DAT_140331c0c;

  if (param_2 != (undefined *)0x0) {

    puVar5 = param_2;

  }

  lVar4 = FUN_14013fc10(&local_18,puVar5,0,1);

  FUN_14015bb10();

  return (ulonglong)(lVar4 != 0);

}




