// Address: 0x140106b90
// Ghidra name: FUN_140106b90
// ============ 0x140106b90 FUN_140106b90 (size=28) ============


undefined8 FUN_140106b90(longlong param_1,int param_2)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  undefined **ppuStack_48;

  longlong lStack_40;

  undefined ***pppuStack_10;

  

  if ((param_2 != 5) && (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0x28), lVar1 != 0))

  {

    if ((*(longlong *)(lVar1 + 0x138) - (longlong)*(undefined8 **)(lVar1 + 0x130) &

        0xfffffffffffffff8U) == 8) {

      cVar2 = FUN_1400b7660(**(undefined8 **)(lVar1 + 0x130),0,0);

      if (cVar2 != '\0') {

        return **(undefined8 **)(lVar1 + 0x130);

      }

    }

    ppuStack_48 = &PTR_LAB_14030fbd0;

    pppuStack_10 = &ppuStack_48;

    lStack_40 = lVar1;

    uVar3 = FUN_1400cfda0(lVar1,&ppuStack_48);

    return uVar3;

  }

  return 0;

}




