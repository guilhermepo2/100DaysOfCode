using UnityEngine;
using System.Collections;

public class IntroSceneManager : MonoBehaviour {

	public void PlayButton()
	{
		Application.LoadLevel ("simon");
	}

	public void OptionsButton()
	{
		Debug.Log ("Options!");
	}

	public void CreditsButton()
	{
		Debug.Log ("Credits!");
	}
}
