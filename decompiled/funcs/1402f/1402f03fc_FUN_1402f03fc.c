// Address: 0x1402f03fc
// Ghidra name: FUN_1402f03fc
// ============ 0x1402f03fc FUN_1402f03fc (size=71) ============


void FUN_1402f03fc(undefined2 *param_1)



{

  ulonglong uVar1;

  uint local_18 [4];

  

  local_18[0] = 0;

  uVar1 = FUN_1402f0198(local_18);

  if (uVar1 < 5) {

    if (0xffff < local_18[0]) {

      local_18[0] = 0xfffd;

    }

    if (param_1 != (undefined2 *)0x0) {

      *param_1 = (short)local_18[0];

    }

  }

  return;

}




