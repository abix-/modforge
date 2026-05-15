// Address: 0x1401aef20
// Ghidra name: FUN_1401aef20
// ============ 0x1401aef20 FUN_1401aef20 (size=118) ============


void FUN_1401aef20(longlong param_1,undefined8 *param_2,int param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  lVar2 = *(longlong *)*param_2;

  FUN_1401bd730(param_1,lVar2);

                    /* WARNING: Could not recover jumptable at 0x0001401aef93. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(lVar1 + 0xa28))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(lVar2 + 0x10),

             *(undefined4 *)(param_2 + 1),*(undefined4 *)(&DAT_1403e4098 + (longlong)param_3 * 4));

  return;

}




