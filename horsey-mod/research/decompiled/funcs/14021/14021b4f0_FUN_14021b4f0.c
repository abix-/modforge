// Address: 0x14021b4f0
// Ghidra name: FUN_14021b4f0
// ============ 0x14021b4f0 FUN_14021b4f0 (size=72) ============


undefined8 * FUN_14021b4f0(longlong param_1,longlong param_2)



{

  _guard_check_icall();

  if (*(undefined ***)(param_2 + 0x140) == &PTR_FUN_1403e4c90) {

    return (undefined8 *)

           CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),

                    param_2 == *(longlong *)(*(longlong *)(param_1 + 0x28) + 8));

  }

  return &DAT_1403e4c00;

}




