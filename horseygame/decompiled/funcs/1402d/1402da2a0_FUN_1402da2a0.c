// Address: 0x1402da2a0
// Ghidra name: FUN_1402da2a0
// ============ 0x1402da2a0 FUN_1402da2a0 (size=132) ============


int FUN_1402da2a0(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 uVar2;

  longlong lVar3;

  undefined1 uVar4;

  longlong lVar5;

  

  uVar1 = param_1[1];

  uVar2 = *(undefined8 *)*param_1;

  uVar4 = FUN_1402eedbc(uVar2);

  lVar5 = FUN_1402d1648(*(undefined8 *)param_1[2],1,*(undefined8 *)param_1[3],

                        *(undefined8 *)*param_1,param_1[1]);

  lVar3 = *(longlong *)param_1[3];

  FUN_1402eee84(CONCAT71((int7)((ulonglong)param_1[3] >> 8),uVar4),uVar2,uVar1);

  return -(uint)(lVar5 != lVar3);

}




