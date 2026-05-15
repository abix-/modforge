// Address: 0x14009e150
// Ghidra name: FUN_14009e150
// ============ 0x14009e150 FUN_14009e150 (size=289) ============


void FUN_14009e150(longlong param_1)



{

  longlong *plVar1;

  char cVar2;

  longlong *plVar3;

  longlong *plVar4;

  longlong *plVar5;

  

  plVar5 = *(longlong **)(param_1 + 0x10);

  plVar1 = (longlong *)(param_1 + 0x10);

  plVar4 = (longlong *)*plVar5;

  if (plVar4 != plVar5) {

    do {

      FUN_1402c7088(plVar4[5],0x28);

      plVar5 = (longlong *)plVar4[2];

      if (*(char *)((longlong)plVar5 + 0x19) == '\0') {

        cVar2 = *(char *)(*plVar5 + 0x19);

        plVar4 = plVar5;

        plVar5 = (longlong *)*plVar5;

        while (cVar2 == '\0') {

          cVar2 = *(char *)(*plVar5 + 0x19);

          plVar4 = plVar5;

          plVar5 = (longlong *)*plVar5;

        }

      }

      else {

        cVar2 = *(char *)(plVar4[1] + 0x19);

        plVar3 = (longlong *)plVar4[1];

        plVar5 = plVar4;

        while ((plVar4 = plVar3, cVar2 == '\0' && (plVar5 == (longlong *)plVar4[2]))) {

          cVar2 = *(char *)(plVar4[1] + 0x19);

          plVar3 = (longlong *)plVar4[1];

          plVar5 = plVar4;

        }

      }

      plVar5 = (longlong *)*plVar1;

    } while (plVar4 != plVar5);

  }

  cVar2 = *(char *)(plVar5[1] + 0x19);

  plVar4 = (longlong *)plVar5[1];

  while (cVar2 == '\0') {

    FUN_14009f2f0(plVar1,plVar1,plVar4[2]);

    plVar3 = (longlong *)*plVar4;

    FUN_1402c7088(plVar4,0x30);

    plVar4 = plVar3;

    cVar2 = *(char *)((longlong)plVar3 + 0x19);

  }

  plVar5[1] = (longlong)plVar5;

  *plVar5 = (longlong)plVar5;

  plVar5[2] = (longlong)plVar5;

  *(undefined8 *)(param_1 + 0x18) = 0;

  cVar2 = *(char *)((longlong)*(longlong **)(*plVar1 + 8) + 0x19);

  plVar5 = *(longlong **)(*plVar1 + 8);

  while (cVar2 == '\0') {

    FUN_14009f2f0(plVar1,plVar1,plVar5[2]);

    plVar4 = (longlong *)*plVar5;

    FUN_1402c7088(plVar5,0x30);

    plVar5 = plVar4;

    cVar2 = *(char *)((longlong)plVar4 + 0x19);

  }

  FUN_1402c7088(*plVar1,0x30);

  return;

}




