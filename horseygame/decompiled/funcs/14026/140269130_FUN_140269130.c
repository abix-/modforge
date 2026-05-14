// Address: 0x140269130
// Ghidra name: FUN_140269130
// ============ 0x140269130 FUN_140269130 (size=198) ============


ulonglong FUN_140269130(longlong *param_1)



{

  undefined2 uVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  longlong local_res8 [4];

  

  local_res8[0] = 0;

  if (*(char *)(*param_1 + 0x54) == '\0') {

    uVar3 = FUN_14026d490(param_1,1,0,0,1);

    if ((char)uVar3 != '\0') {

      uVar2 = FUN_140269280(param_1,*(undefined1 *)((longlong)param_1 + 0x43));

      *(undefined4 *)(param_1 + 4) = uVar2;

      *(undefined1 *)((longlong)param_1 + 0x26) = *(undefined1 *)((longlong)param_1 + 0x49);

      *(char *)((longlong)param_1 + 0x27) = (char)param_1[9];

      *(undefined1 *)(param_1 + 5) = *(undefined1 *)((longlong)param_1 + 0x47);

      *(undefined1 *)((longlong)param_1 + 0x29) = *(undefined1 *)((longlong)param_1 + 0x46);

      *(undefined1 *)((longlong)param_1 + 0x2a) = *(undefined1 *)((longlong)param_1 + 0x45);

      *(undefined1 *)((longlong)param_1 + 0x2b) = *(undefined1 *)((longlong)param_1 + 0x44);

      return 1;

    }

  }

  else {

    uVar3 = FUN_14026d5b0(param_1,2,0,0,local_res8);

    if ((char)uVar3 != '\0') {

      uVar2 = FUN_140269280(param_1,*(undefined1 *)(local_res8[0] + 0x10));

      *(undefined4 *)(param_1 + 4) = uVar2;

      *(undefined4 *)((longlong)param_1 + 0x26) = *(undefined4 *)(local_res8[0] + 0x12);

      uVar1 = *(undefined2 *)(local_res8[0] + 0x16);

      *(undefined2 *)((longlong)param_1 + 0x2a) = uVar1;

      return CONCAT71((uint7)(byte)((ushort)uVar1 >> 8),1);

    }

  }

  return uVar3 & 0xffffffffffffff00;

}




