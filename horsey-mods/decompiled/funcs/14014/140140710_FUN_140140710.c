// Address: 0x140140710
// Ghidra name: FUN_140140710
// ============ 0x140140710 FUN_140140710 (size=185) ============


longlong FUN_140140710(undefined4 param_1,char param_2)



{

  undefined8 uVar1;

  undefined8 uVar2;

  char cVar3;

  undefined8 uVar4;

  undefined8 *puVar5;

  longlong lVar6;

  longlong lVar7;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined1 local_118 [272];

  

  _guard_check_icall();

  uVar4 = FUN_140158780(param_1);

  puVar5 = (undefined8 *)FUN_140158250(&local_128,param_1);

  uVar1 = *puVar5;

  uVar2 = puVar5[1];

  local_128 = uVar1;

  uStack_120 = uVar2;

  lVar6 = FUN_140140960(uVar4,&local_128);

  if ((lVar6 == 0) && (lVar6 = DAT_1403fbf20, param_2 != '\0')) {

    FUN_1402f94c0(local_118,0,0x100);

    cVar3 = FUN_14015a4e0(param_1,local_118);

    lVar6 = DAT_1403fbf20;

    if ((cVar3 != '\0') &&

       (local_128 = uVar1, uStack_120 = uVar2, lVar7 = FUN_140140130(uVar4,&local_128,local_118),

       lVar6 = DAT_1403fbf20, lVar7 != 0)) {

      return lVar7;

    }

  }

  return lVar6;

}




