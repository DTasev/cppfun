CoordMode, Tooltip, Screen
GoSub, Constants
SynAPI := ComObjCreate("SynCtrl.SynAPICtrl")
SynDev := ComObjCreate("SynCtrl.SynDeviceCtrl")
SynAPI.Initialize
SynDev.Select( SynAPI.FindDevice(0,2,-1) )
SynPac := ComObjCreate("SynCtrl.SynPacketCtrl")
Loop
{
	SynDev.LoadPacket(SynPac)
	FingerState := SynPac.GetLongProperty(268436243) ; This value is wrong, I was trying to follow enums in a header file to get it...
	Loop, Parse, SF_List, `n
		If (%A_LoopField% = FingerState)
			ToolTip, FingerState: %FingerState% `nActon: %A_LoopField% `n, 0, 0
	Sleep 0
}
return

Esc::ExitApp

Constants:
SF_FingerProx := 0x00000200
SF_FingerTouch := 0x00000400 
SF_FingerHeavy := 0x00000800 
SF_FingerPress := 0x00001000 
SF_FingerPresent := 0x00002000 
SF_FingerPossTap := 0x00004000 
SF_FingerStylus := 0x00008000 

SF_FingerTap := 0x00010000 
SF_FingerDrag := 0x00020000 
SF_FingerDragLock := 0x00040000 
SF_FingerPrimGest := 0x00080000 
SF_FingerSecGest := 0x00100000 
SF_FingerAuxGest := 0x00200000 
SF_FingerMotion := 0x00400000 
SF_FingerMoving := 0x00800000 

SF_FingerTopLeftTap := 0x01000000 
SF_FingerTopRightTap := 0x02000000 
SF_FingerBottomLeftTap := 0x04000000 
SF_FingerBottomRightTap := 0x08000000 

SF_FingerTap2 := 0x40000000 
SF_FingerTap3 := 0x80000000 

SF_FingerAllCorner := 0x0F000000 
SF_FingerAllTap := 0xCF000000 
SF_FingerAsButton := 0xCF380000 
SF_FingerAllGest := 0xCF3F1000

SF_List =
(
SF_FingerProx 
SF_FingerTouch 
SF_FingerHeavy 
SF_FingerPress 
SF_FingerPresent 
SF_FingerPossTap 
SF_FingerStylus
SF_FingerTap 
SF_FingerDrag 
SF_FingerDragLock 
SF_FingerPrimGest 
SF_FingerSecGest 
SF_FingerAuxGest 
SF_FingerMotion 
SF_FingerMoving
SF_FingerTopLeftTap 
SF_FingerTopRightTap 
SF_FingerBottomLeftTap 
SF_FingerBottomRightTap
SF_FingerTap2 
SF_FingerTap3
SF_FingerAllCorner 
SF_FingerAllTap 
SF_FingerAsButton 
SF_FingerAllGest 
)
return