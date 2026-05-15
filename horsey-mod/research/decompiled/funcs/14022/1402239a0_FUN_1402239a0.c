// Address: 0x1402239a0
// Ghidra name: FUN_1402239a0
// ============ 0x1402239a0 FUN_1402239a0 (size=105) ============


void FUN_1402239a0(undefined8 *param_1,int param_2,int param_3,int param_4,int param_5)



{

  HRGN hrgnDst;

  HRGN hrgnSrc2;

  

  hrgnSrc2 = CreateRectRgn(param_2,param_3,param_4,param_5);

  hrgnDst = (HRGN)*param_1;

  if (hrgnDst != (HRGN)0x0) {

    CombineRgn(hrgnDst,hrgnDst,hrgnSrc2,2);

                    /* WARNING: Could not recover jumptable at 0x0001402239f4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    DeleteObject(hrgnSrc2);

    return;

  }

  *param_1 = hrgnSrc2;

  return;

}




