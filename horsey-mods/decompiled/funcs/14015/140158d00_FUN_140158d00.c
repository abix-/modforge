// Address: 0x140158d00
// Ghidra name: FUN_140158d00
// ============ 0x140158d00 FUN_140158d00 (size=78) ============


ulonglong FUN_140158d00(undefined4 param_1)



{

  char cVar1;

  undefined4 *puVar2;

  ulonglong uVar3;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  puVar2 = (undefined4 *)FUN_140158250(&local_18,param_1);

  local_18 = *puVar2;

  uStack_14 = puVar2[1];

  uStack_10 = puVar2[2];

  uStack_c = puVar2[3];

  uVar3 = FUN_140158360(&local_18);

  if (((int)uVar3 == 0) &&

     (cVar1 = FUN_14013f5e0(param_1), uVar3 = uVar3 & 0xffffffff, cVar1 != '\0')) {

    uVar3 = 1;

  }

  return uVar3;

}




