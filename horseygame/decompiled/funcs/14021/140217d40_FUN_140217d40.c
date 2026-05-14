// Address: 0x140217d40
// Ghidra name: FUN_140217d40
// ============ 0x140217d40 FUN_140217d40 (size=119) ============


ulonglong FUN_140217d40(undefined8 param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined1 local_res10 [8];

  longlong local_res18;

  undefined1 local_res20 [8];

  undefined1 local_18 [16];

  

  uVar2 = 0;

  local_res18 = FUN_140217b30();

  while( true ) {

    if (local_res18 == 0) {

      return uVar2;

    }

    uVar1 = FUN_140217dc0(param_1,&local_res18,local_18,local_res20,local_res10);

    if (~uVar2 <= uVar1) break;

    uVar2 = uVar2 + uVar1;

  }

  return 0xffffffffffffffff;

}




