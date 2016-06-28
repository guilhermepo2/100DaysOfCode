using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class SimonBoard : MonoBehaviour {
	[Header("Buttons' Gameobjects")]
	public GameObject redButton;
	public GameObject blueButton;
	public GameObject yellowButton;
	public GameObject greenButton;
	[Header("Controls")]
	public float waitTime = 0.5f;

	public static SimonBoard instance = null;

	public static SimonBoard getInstance()
	{
		return instance;
	}

	void Awake()
	{
		if (instance == null)
			instance = this;
		else if (instance != this)
			Destroy (gameObject);

		DontDestroyOnLoad(gameObject);
	}

	public IEnumerator playSequence(List<int> sequence)
	{
		for (int i = 0; i < sequence.Count; i++) 
		{
			Color tempColor;
			switch(sequence[i])
			{
			case 0:
				tempColor = redButton.GetComponent<SpriteRenderer> ().color;
				redButton.GetComponent<SpriteRenderer> ().color = new Color (1.0f, 1.0f, 1.0f);
				yield return new WaitForSeconds (waitTime);
				redButton.GetComponent<SpriteRenderer> ().color = tempColor;
				break;
			case 1:
				tempColor = blueButton.GetComponent<SpriteRenderer> ().color;
				blueButton.GetComponent<SpriteRenderer> ().color = new Color (1.0f, 1.0f, 1.0f);
				yield return new WaitForSeconds (waitTime);
				blueButton.GetComponent<SpriteRenderer> ().color = tempColor;
				break;
			case 2:
				tempColor = yellowButton.GetComponent<SpriteRenderer> ().color;
				yellowButton.GetComponent<SpriteRenderer> ().color = new Color (1.0f, 1.0f, 1.0f);
				yield return new WaitForSeconds (waitTime);
				yellowButton.GetComponent<SpriteRenderer> ().color = tempColor;
				break;
			case 3:
				tempColor = greenButton.GetComponent<SpriteRenderer> ().color;
				greenButton.GetComponent<SpriteRenderer> ().color = new Color (1.0f, 1.0f, 1.0f);
				yield return new WaitForSeconds (waitTime);
				greenButton.GetComponent<SpriteRenderer> ().color = tempColor;
				break;
			}
			yield return new WaitForSeconds (waitTime);
		}
	}
}
