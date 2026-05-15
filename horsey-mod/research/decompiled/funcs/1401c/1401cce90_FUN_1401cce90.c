// Address: 0x1401cce90
// Ghidra name: FUN_1401cce90
// ============ 0x1401cce90 FUN_1401cce90 (size=178) ============


void FUN_1401cce90(longlong param_1,longlong *param_2,undefined8 *param_3,undefined1 param_4)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_2;

  lVar2 = FUN_1401ca8a0(param_1,*param_3,param_4,0x400);

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x78))

            (*(longlong **)(param_1 + 0x120),*(undefined8 *)(lVar2 + 0x10),

             *(undefined4 *)(param_3 + 1),*(undefined8 *)(*(longlong *)(lVar1 + 0x10) + 0x10),

             (int)param_2[1],*(undefined4 *)((longlong)param_3 + 0xc));

  FUN_1401c6930(param_1,0x400,lVar2);

  FUN_1401cb5f0(param_1,*(undefined8 *)(lVar1 + 0x10));

  FUN_1401cb5f0(param_1,lVar2);

  return;

}




