using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class GameOverSceneManager : MonoBehaviour {

	public Text scoreText;

	void Start()
	{
		scoreText.text = "Score: " + (PlayerPrefs.GetInt("score"));
	}

	public void PlayAgain()
	{
		Application.LoadLevel ("simon");
	}

	public void MainMenu()
	{
		Application.LoadLevel ("intro");
	}
}
