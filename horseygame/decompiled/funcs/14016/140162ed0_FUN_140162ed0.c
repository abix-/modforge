// Address: 0x140162ed0
// Ghidra name: FUN_140162ed0
// ============ 0x140162ed0 FUN_140162ed0 (size=110) ============


void FUN_140162ed0(void)



{

  uint uVar1;

  ulonglong *puVar2;

  longlong lVar3;

  ulonglong uVar4;

  

  lVar3 = FUN_1401611a0();

  if ((((*(longlong **)(lVar3 + 0x120) != (longlong *)0x0) &&

       (puVar2 = (ulonglong *)**(longlong **)(lVar3 + 0x120), puVar2 != (ulonglong *)0x0)) &&

      (*(longlong *)(lVar3 + 0x88) != 0)) &&

     ((uVar1 = *(uint *)(puVar2[3] + (longlong)*(int *)((longlong)puVar2 + 0xc) * 4), uVar1 != 0 &&

      (uVar4 = FUN_140149350(), (ulonglong)uVar1 + *puVar2 <= uVar4)))) {

    *puVar2 = uVar4;

    *(int *)((longlong)puVar2 + 0xc) = (*(int *)((longlong)puVar2 + 0xc) + 1) % (int)puVar2[1];

    FUN_140162700();

  }

  return;

}




