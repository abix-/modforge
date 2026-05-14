// Address: 0x1402d3cbc
// Ghidra name: FUN_1402d3cbc
// ============ 0x1402d3cbc FUN_1402d3cbc (size=284) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined4 FUN_1402d3cbc(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 uVar2;

  undefined1 uVar3;

  undefined4 uVar4;

  undefined1 auStack_4c8 [32];

  undefined8 local_4a8;

  undefined8 local_4a0;

  undefined8 local_498;

  undefined8 local_490;

  undefined4 local_488;

  undefined1 local_484;

  undefined8 local_480;

  undefined4 local_478;

  undefined1 local_470;

  undefined2 local_46e;

  undefined4 local_460;

  undefined1 local_45c;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined4 local_40;

  ulonglong local_38;

  

  local_38 = DAT_1403e8b00 ^ (ulonglong)auStack_4c8;

  uVar1 = param_1[1];

  uVar2 = *(undefined8 *)*param_1;

  uVar3 = FUN_1402eedbc(uVar2);

  local_490 = *(undefined8 *)param_1[4];

  local_48 = *(undefined8 *)*param_1;

  local_498 = *(undefined8 *)param_1[3];

  local_4a8 = *(undefined8 *)param_1[2];

  local_4a0 = param_1[1];

  local_488 = 0;

  local_484 = 0;

  local_480 = 0;

  local_478 = 0;

  local_470 = 0;

  local_46e = 0;

  local_460 = 0;

  local_45c = 0;

  local_58 = 0;

  uStack_50 = 0;

  local_40 = 0;

  uVar4 = FUN_1402d49c0(&local_4a8);

  FUN_1402e9a80(uStack_50);

  uStack_50 = 0;

  FUN_1402eee84(uVar3,uVar2,uVar1);

  return uVar4;

}




